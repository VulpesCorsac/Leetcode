class Solution {
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrlCode = "";
        if (!longToShort.count(longUrl)){
            do {
                for (int i = 0; i < 6; ++i)
                    shortUrlCode += charset[rand() % charset.size()];
            } while (shortToLong.count(shortUrlCode)) ;
            
            longToShort[longUrl] = shortUrlCode;
            shortToLong[shortUrlCode] = longUrl;
        } else
            shortUrlCode = longToShort[longUrl];
        return "http://tinyurl.com/" + shortUrlCode;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return shortToLong[shortUrl.substr(19, 6)];
    }

private:
    string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    unordered_map<string,string> longToShort, shortToLong;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
