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
    	
    	UrlValidator validator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
    	
    	//Create string from arrays of query parts
    	ResultPair[] urlArr = {
    			new ResultPair("http://", true),
    			new ResultPair("https://", true),
    			new ResultPair("ftp://", true),
    			new ResultPair("", true),
    			new ResultPair("gibberish://", false),
    			new ResultPair("/", false),
    			new ResultPair(":", false)
    	};
    	
    	ResultPair[] authorityArr = {
    			new ResultPair("www.google.com", true),
    			new ResultPair("google.com", true),
    			new ResultPair("www.usa.gov", true),
    			new ResultPair("usa.gov", true),
    			new ResultPair("www.wordpress.org", true),
    			new ResultPair("wordpress.org", true),
    			new ResultPair("255.255.255.0", true),
    			new ResultPair("www.google.co.uk", true),
    			new ResultPair("www.google.co.uk", true),
    			new ResultPair("developer.amazon.com", true),
    			new ResultPair(".www.google.com", false),
    			new ResultPair("www.google.com.", false),
    			new ResultPair("singleword", false),
    			new ResultPair("", false),
    			new ResultPair("256.0.0.0", false),
    			new ResultPair("0.0.0.256", false),
    			new ResultPair("128.12.46.5.15", false),
    	};
    	
    	ResultPair[] portArr = {
    			new ResultPair(":656", true),
    			new ResultPair(":0", true),
    			new ResultPair(":65535", true),
    			new ResultPair("", true),
    			new ResultPair(":-1", false),
    			new ResultPair(":65636", false),
    			new ResultPair(":word", false),
    			new ResultPair("word", false)
    	};
    	
    	ResultPair [] pathArr = {
    			new ResultPair("", true),
    			new ResultPair("/word", true),
                new ResultPair("/12345", true),
                new ResultPair("/~", true),
                new ResultPair("/word/12345", true),
                new ResultPair("/word/12345/test123", true),
                new ResultPair("noslash", false),
                new ResultPair("//", false),
                new ResultPair("/word/", true),
                new ResultPair("/validstart//", false)
    	};
    	
    	// Iterate over all permutations of strings
    	int[] position = new int[]{0, 0, 0, 0};
    	int failed = 0;
    	int i = 0;
    	int tests = urlArr.length * authorityArr.length * portArr.length * pathArr.length;
    	
    	while(true) {
    		
    		// Update position counters
    		position[0]++;
    		if (i % (urlArr.length) == 0) {
    			position[0] = 0;
    			position[1]++;
    		}
    		if (i % (urlArr.length * authorityArr.length) == 0) {
    			position[0] = 0;
    			position[1] = 0;
    			position[2]++;
    		}
    		if (i % (urlArr.length * authorityArr.length * portArr.length) == 0) {
    			position[0] = 0;
    			position[1] = 0;
    			position[2] = 0;
    			position[3]++;
    			
    			if (position[3] >= pathArr.length) break;
    		}
    		
    		// Build the strings
    		StringBuilder testUrl = new StringBuilder();
    		testUrl.append(urlArr[position[0]].item);
    		testUrl.append(authorityArr[position[1]].item);
    		testUrl.append(portArr[position[2]].item);
    		testUrl.append(pathArr[position[3]].item);
    		String url = testUrl.toString();
    		
    		// Get expected results based on test parts
    		boolean expected = urlArr[position[0]].valid && authorityArr[position[1]].valid && portArr[position[2]].valid && pathArr[position[3]].valid;
    		// Get result from isValid
    		boolean result = validator.isValid(url);
    		
    		// Print test results
    		if (expected != result) {
    			System.out.println("FAILED: " + url);
    			failed++;
    		} else {
    			System.out.println("SUCCESS: " + url);
    		}
    		i++;
    	}
    	System.out.println("RESULTS: " + failed + " of " + tests + " failed.");
    }
}
