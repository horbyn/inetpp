include_directories(
    ${PROJECT_SOURCE_DIR}
)
aux_source_directory(. DIR_INETSOCK)
add_library(mod_inetsock OBJECT ${DIR_INETSOCK})
