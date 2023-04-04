add_executable (LXEngine "LXEngine.cpp" "LXEngine.h" "log.h" "pch.h" "pch.cpp" "log.cpp" "Application.h" "Application.cpp")
target_precompile_headers(${PROJECT_NAME} PRIVATE "pch.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET LXEngine PROPERTY CXX_STANDARD 20)
endif()