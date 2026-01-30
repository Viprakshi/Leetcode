class Solution {
public:
  long long minimumCost(string source, string target, vector<string>& original,
                        vector<string>& changed, vector<int>& cost) {
    const unordered_set<int> sub_lengths = getSubLengths(original);
    const unordered_map<string, int> sub_to_id = getSubToId(original, changed);
    const int sub_count = sub_to_id.size();
    vector<vector<long>> dist(sub_count, vector<long>(sub_count, LONG_MAX));
    vector<long> dp(source.length() + 1, LONG_MAX);
    for (int i = 0; i < cost.size(); ++i) {
      const int u = sub_to_id.at(original[i]);
      const int v = sub_to_id.at(changed[i]);
      dist[u][v] = min(dist[u][v], static_cast<long>(cost[i]));
    }
    for (int k = 0; k < sub_count; ++k)
      for (int i = 0; i < sub_count; ++i)
        if (dist[i][k] < LONG_MAX)
          for (int j = 0; j < sub_count; ++j)
            if (dist[k][j] < LONG_MAX)
              dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    dp[0] = 0;
    for (int i = 0; i < source.length(); ++i) {
      if (dp[i] == LONG_MAX)
        continue;
      if (target[i] == source[i])
        dp[i + 1] = min(dp[i + 1], dp[i]);
      for (const int sub_length : sub_lengths) {
        if (i + sub_length > source.length())
          continue;
        const string sub_source = source.substr(i, sub_length);
        const string sub_target = target.substr(i, sub_length);
        if (!sub_to_id.contains(sub_source) || !sub_to_id.contains(sub_target))
          continue;
        const int u = sub_to_id.at(sub_source);
        const int v = sub_to_id.at(sub_target);
        if (dist[u][v] < LONG_MAX)
          dp[i + sub_length] = min(dp[i + sub_length], dp[i] + dist[u][v]);
      }
    }
    return dp[source.length()] == LONG_MAX ? -1 : dp[source.length()];
  }
private:
  unordered_map<string, int> getSubToId(const vector<string>& original,
                                        const vector<string>& changed) {
    unordered_map<string, int> sub_to_id;
    for (const string& s : original)
      if (!sub_to_id.contains(s))
        sub_to_id[s] = sub_to_id.size();
    for (const string& s : changed)
      if (!sub_to_id.contains(s))
        sub_to_id[s] = sub_to_id.size();
    return sub_to_id;
  }
  unordered_set<int> getSubLengths(const vector<string>& original) {
    unordered_set<int> sub_lengths;
    for (const string& s : original)
      sub_lengths.insert(s.length());
    return sub_lengths;
  }
};