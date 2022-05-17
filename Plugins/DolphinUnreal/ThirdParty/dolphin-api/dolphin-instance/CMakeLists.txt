add_executable(dolphin-instance
  Platform.cpp
  Platform.h
  PlatformHeadless.cpp
  MainNoGUI.cpp
)

if(ENABLE_X11 AND X11_FOUND)
  target_sources(dolphin-instance PRIVATE PlatformX11.cpp)
endif()

if(WIN32)
  target_sources(dolphin-instance PRIVATE PlatformWin32.cpp)
endif()

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
  target_sources(dolphin-instance PRIVATE PlatformFBDev.cpp)
endif()

set_target_properties(dolphin-instance PROPERTIES OUTPUT_NAME dolphin-emu-instance)

target_link_libraries(dolphin-instance
PRIVATE
  core
  uicommon
  cpp-optparse
)

if(USE_DISCORD_PRESENCE)
  target_compile_definitions(dolphin-instance PRIVATE -DUSE_DISCORD_PRESENCE)
endif()

set(CPACK_PACKAGE_EXECUTABLES ${CPACK_PACKAGE_EXECUTABLES} dolphin-instance)
install(TARGETS dolphin-instance RUNTIME DESTINATION ${bindir})

