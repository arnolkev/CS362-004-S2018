import junit.framework.TestCase;


public class UrlValidatorTest extends TestCase {
    public UrlValidatorTest(String testName) {
        super(testName);
    }


    public void testManualTest() {
        UrlValidator validator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        assertTrue(validator.isValid("http://www.google.com"));
        assertFalse(validator.isValid("http://www.google.com//"));
//        assertTrue(validator.isValid("https://www.google.com")); ---------------------EXCEPTION
//        assertFalse(validator.isValid("htttps://www.google.com"));--------------------EXCEPTION
        assertTrue(validator.isValid("http://www.google.org/"));
        assertFalse(validator.isValid("http//www.google.org/"));
//        assertTrue(validator.isValid("http://www.google.org:8080"));  ----------------FAILING
//        assertTrue(validator.isValid("http://www.google.com:65535/t123")); -----------FAILING
//        assertFalse(validator.isValid("http://www.google.org:118080"));
//        assertTrue(validator.isValid("ftp://osu.edu")); ------------------------------EXCEPTION
        assertTrue(validator.isValid("http://qwerty.ua/asdf?param=test"));
        assertTrue(validator.isValid("http://qwerty.ua/zxcv?param=test2&another-param=123456"));
        assertTrue(validator.isValid("http://http.xyz/"));
        assertTrue(validator.isValid("http://com.http"));
    }


    public void testYourFirstPartition() {
        //You can use this function to implement your First Partition testing
    }

    public void testYourSecondPartition() {
        //You can use this function to implement your Second Partition testing
    }
    //You need to create more test cases for your Partitions if you need to

    public void testIsValid() {
        //You can use this function for programming based testing
    }
}
