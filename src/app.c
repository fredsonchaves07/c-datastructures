# include "../modules/Unity/unity.h"
# include "../include/app.h"

void setUp() {}

void tearDown() {}

void test_app() {
    TEST_ASSERT_EQUAL(0, function());
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_app);
    return UNITY_END();
}

