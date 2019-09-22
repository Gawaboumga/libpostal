
add_library(libscanner_la SHARED klib/drand48.c scanner.c)

configure_file(${CMAKE_SOURCE_DIR}/libpostal.pc.in ${CMAKE_SOURCE_DIR}/src/config.h)

include_directories(${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/windows)

# Main libs

add_library(libpostal_la STATIC strndup.c libpostal.c expand.c address_dictionary.c transliterate.c tokens.c trie.c trie_search.c trie_utils.c string_utils.c file_utils.c utf8proc/utf8proc.c normalize.c numex.c features.c unicode_scripts.c address_parser.c address_parser_io.c averaged_perceptron.c crf.c crf_context.c sparse_matrix.c averaged_perceptron_tagger.c graph.c graph_builder.c language_classifier.c language_features.c logistic_regression.c logistic.c minibatch.c float_utils.c ngrams.c place.c near_dupe.c double_metaphone.c geohash/geohash.c dedupe.c string_similarity.c acronyms.c soft_tfidf.c jaccard.c)
target_link_libraries(libpostal_la libscanner_la)

add_executable(libpostal strndup.c main.c json_encode.c file_utils.c string_utils.c utf8proc/utf8proc.c scanner.c)
target_link_libraries(libpostal libpostal_la)

# 

add_executable(bench bench.c)
target_link_libraries(bench libpostal_la libscanner_la)

add_executable(address_parser strndup.c address_parser_cli.c json_encode.c linenoise/linenoise.c string_utils.c utf8proc/utf8proc.c scanner.c)
target_link_libraries(address_parser libpostal_la)

#

add_executable(near_dupe_test strndup.c near_dupe_test.c string_utils.c utf8proc/utf8proc.c)
target_link_libraries(near_dupe_test libpostal_la)

#

add_executable(build_address_dictionary strndup.c address_dictionary_builder.c address_dictionary.c file_utils.c string_utils.c trie.c trie_search.c utf8proc/utf8proc.c)

add_executable(build_numex_table strndup.c transliteration_table_builder.c transliterate.c trie.c trie_search.c file_utils.c string_utils.c utf8proc/utf8proc.c)

add_executable(address_parser_train strndup.c address_parser_train.c address_parser.c address_parser_io.c averaged_perceptron.c crf.c crf_context.c sparse_matrix.c graph.c graph_builder.c float_utils.c averaged_perceptron_trainer.c crf_trainer.c crf_trainer_averaged_perceptron.c averaged_perceptron_tagger.c address_dictionary.c normalize.c numex.c features.c unicode_scripts.c transliterate.c trie.c trie_search.c trie_utils.c string_utils.c tokens.c file_utils.c shuffle.c utf8proc/utf8proc.c ngrams.c)
target_link_libraries(address_parser_train libscanner_la)

#

add_executable(address_parser_test strndup.c address_parser_test.c address_parser.c address_parser_io.c averaged_perceptron.c crf.c crf_context.c sparse_matrix.c graph.c graph_builder.c float_utils.c averaged_perceptron_tagger.c address_dictionary.c normalize.c numex.c features.c unicode_scripts.c transliterate.c trie.c trie_search.c trie_utils.c string_utils.c tokens.c file_utils.c utf8proc/utf8proc.c ngrams.c)
target_link_libraries(address_parser_test libscanner_la)

#

add_executable(language_classifier_train strndup.c language_classifier_train.c language_classifier.c language_features.c language_classifier_io.c logistic_regression_trainer.c logistic_regression.c logistic.c sparse_matrix.c sparse_matrix_utils.c features.c minibatch.c float_utils.c stochastic_gradient_descent.c ftrl.c regularization.c cartesian_product.c normalize.c numex.c transliterate.c trie.c trie_search.c trie_utils.c address_dictionary.c string_utils.c file_utils.c utf8proc/utf8proc.c unicode_scripts.c shuffle.c)
target_link_libraries(language_classifier_train libscanner_la)

add_executable(language_classifier strndup.c language_classifier_cli.c language_classifier.c language_features.c logistic_regression.c logistic.c sparse_matrix.c features.c minibatch.c float_utils.c normalize.c numex.c transliterate.c trie.c trie_search.c trie_utils.c address_dictionary.c string_utils.c file_utils.c utf8proc/utf8proc.c unicode_scripts.c)
target_link_libraries(language_classifier libscanner_la)

add_executable(language_classifier_test strndup.c language_classifier_test.c language_classifier.c language_classifier_io.c language_features.c logistic_regression.c logistic.c sparse_matrix.c features.c minibatch.c float_utils.c normalize.c numex.c transliterate.c trie.c trie_search.c trie_utils.c address_dictionary.c string_utils.c file_utils.c utf8proc/utf8proc.c unicode_scripts.c)
target_link_libraries(language_classifier_test libscanner_la)
