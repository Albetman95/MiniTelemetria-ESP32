idf_component_register(
    SRCS
        "main.c"
        "app_info.c"
    INCLUDE_DIRS
        "."
)
list(APPEND EXTRA_COMPONENT_DIRS components)