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
        UrlValidator validator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        //testing valid and invalid URL Schemes
        String[] goodSchemes = {"", "h://", "http://", "f5p://", "f-.+p://", "ftttttttttp://"}
        String[] badSchemes = {"://", "3ttp://", "f$p://" "h:", "h//", "h:/"}
        int i;
        for (i = 0; i < goodSchemes.length; i++){
            StringBuilder tester = goodSchemes[i];
            tester.append("www.google.com");
            assertTrue(validator.isValid(tester));
        }
        for (i = 0; i < badSchemes.length; i++){
            StringBuilder tester = badSchemes[i];
            tester.append("www.google.com");
            assertFalse(validator.isValid(tester));
        }


    }

    public void testYourSecondPartition() {
        UrlValidator validator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
         //testing valid and invalid URL authoirities
        String[] goodAuth = {"www.google.com", "w.google.com", "google.com", "g00gle.com", "g.com", "google.ca", "0.0.0.0", "1.1.1.1", "255.255.255.255" }
        String[] badAuth = { "", "www..com", ".com", "google.", "g$$gle.com", "256.256.256.256", "0.0.0", "0.0.0.0.0", ".0.0.0.0", "0.0.0.0.", "-1.-1.-1.-1" }
        int i;
        for (i = 0; i < goodAuth.length; i++){
            StringBuilder tester = "http://";
            tester.append(goodAuth[i]);
            assertTrue(validator.isValid(tester));
        }
        for (i = 0; i < badAuth.length; i++){
            StringBuilder tester = "http://";
            tester.append(badAuth[i]);
            assertFalse(validator.isValid(tester));
        }

    }
    public void testYourThirdPartition() {
        UrlValidator validator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
              //testing valid and invalid URL ports
        String[] goodPort = {"", ":0", ":1", ":80", ":65535" }
        String[] badPort = {":65536", ":-1", ":1a", ":a" }
        int i;
        for (i = 0; i < goodPort.length; i++){
            StringBuilder tester = "http://www.google.com";
            tester.append(goodPort[i]);
            assertTrue(validator.isValid(tester));
        }
        for (i = 0; i < badPort.length; i++){
            StringBuilder tester = "http://www.google.com";
            tester.append(badPort[i]);
            assertFalse(validator.isValid(tester));
        }
    }
    public void testYourFourthPartition() {
        UrlValidator validator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
              //testing valid and invalid URL paths
        String[] goodPath = {"", "/valid","/v1%", "/111", "/&&&", "/this/is/vaild", "/stillvaild/"}
        String[] badPath = {"//invalid", "/this//alsoinvalid", "/not:good/", }
        int i;
        for (i = 0; i < goodPath.length; i++){
            StringBuilder tester = "http://www.google.com";
            tester.append(goodPath[i]);
            assertTrue(validator.isValid(tester));
        }
        for (i = 0; i < badPath.length; i++){
            StringBuilder tester = "http://www.google.com";
            tester.append(badPath[i]);
            assertFalse(validator.isValid(tester));
        }
    }
    public void testYourFifthPartition() {
        UrlValidator validator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
               //testing valid and invalid URL query
        String[] goodQ = { "", "?this=good", "?this=good&sois=this", "?this=good;sois=this", "?works=this+thing+works" }
        String[] badQ = { "?"}
        int i;
        for (i = 0; i < goodQ.length; i++){
            StringBuilder tester = "http://www.google.com";
            tester.append(goodQ[i]);
            assertTrue(validator.isValid(tester));
        }
        for (i = 0; i < badQ.length; i++){
            StringBuilder tester = "http://www.google.com";
            tester.append(badQ[i]);
            assertFalse(validator.isValid(tester));
        }
    }
    public void testIsValid() {
        //You can use this function for programming based testing
    }
}

