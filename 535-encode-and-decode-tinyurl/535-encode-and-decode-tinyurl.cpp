class Solution {
public:

    // Encodes a URL to a shortened URL.
    unordered_map<string,string> m;
    int i=0;
    string encode(string longUrl) {
        string url="http://shortUrl/"+i;
        m[url]=longUrl;
        i++;
        return url;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));