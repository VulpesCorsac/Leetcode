static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int lengthLongestPath(string input) {
        stack < string > path;
        int result = 0;
        int current_path_length = 0;
        istringstream is(input);

        for (string line; getline(is, line); ) {
            auto depth = line.find_first_not_of('\t');

            while (depth < path.size()) {
                current_path_length -= path.top().size() + 1;
                path.pop();
            }

            auto name = line.substr(depth);
            bool is_file = name.find('.') != string::npos;

            if (is_file) {
                result = max(result, current_path_length + 1 + static_cast<int>(name.size()));
            } else {
                current_path_length += 1 + static_cast<int>(name.size());
                path.push(name);
            }
        }

        return max(0, result-1);
    }
};