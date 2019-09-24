
include_directories(${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/windows)

add_executable(test_libpostal test.c test_expand.c test_parser.c test_transliterate.c test_numex.c test_trie.c test_string_utils.c test_crf_context.c ../src/strndup.c ../src/file_utils.c ../src/string_utils.c ../src/utf8proc/utf8proc.c ../src/trie.c ../src/trie_search.c ../src/transliterate.c ../src/numex.c ../src/features.c ../src/scanner.c)
target_link_libraries(test_libpostal PUBLIC postal)
