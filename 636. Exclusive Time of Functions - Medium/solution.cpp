static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    vector<int> exclusiveTime(int n, vector < string > &logs) {
        vector < int > result(n, 0);
        stack < int > st;

        int last_time_in_stack = 0;

        for (const auto& log : logs) {
            int id;
            bool start;
            int time;

            parse(log, id, start, time);

            if (start) {
                if (!st.empty()) {
                    result[st.top()] += time - last_time_in_stack;
                }

                st.push(id);

                last_time_in_stack = time;
            } else {
                result[st.top()] += time - last_time_in_stack + 1;

                st.pop();

                last_time_in_stack = time+1;
            }
        }

        return result;
    }

    void parse(const string &s, int &id, bool &start, int &time) {
        vector < string > splitted = split(s);

        id = stoi(splitted[0]);
        start = splitted[1][0] == 's' ? true : false;
        time = stoi(splitted[2]);

        return;
    }

    vector < string > split(const string &s, char delim = ':') {
        stringstream ss(s);
        string item;
        vector < string > elems;

        while (getline(ss, item, delim)) {
            elems.push_back(move(item));
        }

        return elems;
    }
};