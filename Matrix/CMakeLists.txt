add_library(Matrix matrix.cpp)

target_include_directories(Matrix PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/include"
                            )