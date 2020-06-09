static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        bool succeeded = false;
        string shortUrl = "";

        do {
            shortUrl.clear();
            for (int i = 0; i < short_url_length; ++i) {
                shortUrl += alphabet[rand() % alphabet.size()];
            }

            if (database.count(shortUrl) == 0) {
                succeeded = true;
            }
        } while (!succeeded);

        shortUrl = prefix + shortUrl;
        database[shortUrl] = longUrl;

        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return database[shortUrl];
    }

private:
    string prefix = "http://tinyurl.com/";
    string alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int short_url_length = 6;
    map<string,string> database;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));