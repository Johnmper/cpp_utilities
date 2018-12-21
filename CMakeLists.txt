cmake_minimum_required(VERSION 3.2)
# Define a variavel ${PROJECT_NAME} = "simple_template"
project(ul)

## Directorias a incluir
include_directories(include /usr/include/eigen3)

## Testing subdirectory
add_subdirectory(tests)
