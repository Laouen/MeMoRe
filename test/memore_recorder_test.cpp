#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <memore/recorder.hpp>

BOOST_AUTO_TEST_SUITE( json_translation_test_suite )

    BOOST_AUTO_TEST_CASE( a_simple_model_test ) {

            memore::Recorder r("laouen", "db_test", "collection_test");
            r.addData({{"hola", "1"}, {"chau", "2"}});
            BOOST_CHECK_EQUAL(1, 1);
    }

    BOOST_AUTO_TEST_CASE( a_simple_model_test ) {

            memore::Recorder r("laouen", "db_test", "collection_test");
            r.addData("{{\"hola\", \"1\"}, {\"chau\", \"2\"}}");
            BOOST_CHECK_EQUAL(1, 1);
    }

BOOST_AUTO_TEST_SUITE_END()