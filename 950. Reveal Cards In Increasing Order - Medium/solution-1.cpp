static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());

        vector<int> simulation_result_positions;
        simulation_result_positions.reserve(deck.size());

        deque<int> simulation;
        for (int i = 0; i < deck.size(); ++i) {
             simulation.push_back(i);
        }

        while (!simulation.empty()) {
            simulation_result_positions.push_back(simulation.front());
            simulation.pop_front();

            if (!simulation.empty()) {
                simulation.push_back(simulation.front());
                simulation.pop_front();
            }
        }

        vector<int> ans = deck;
        for (int i = 0; i < deck.size(); ++i) {
            ans[simulation_result_positions[i]] = deck[i];
        }

        return ans;
    }
};