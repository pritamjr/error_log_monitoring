#include<bits/stdc++.h>

using namespace std;

//data structure to store log data
struct LogEntry {
    long long timestamp;
    string log_type;
    double severity;
};

map<long long, LogEntry> entries; 

void add(long long timestmp, const string& log_type, double severity) {
    entries[timestmp] = {timestmp, log_type, severity};
}


void stats(long long before, long long after, const string& log_type, bool all_types, double& min_severity, double& max_severity, double& mean_severity, int& count) {
    min_severity = numeric_limits<double>::max();
    max_severity = numeric_limits<double>::min();
    mean_severity = 0.0;
    count = 0;

    for (auto it : entries) {
        const LogEntry& entry = it.second;
        if ((all_types || entry.log_type == log_type) &&
            ((before > entry.timestamp && entry.timestamp >= after) ||
             (!before && entry.timestamp > after))) {
            min_severity = min(min_severity, entry.severity);
            max_severity = max(max_severity, entry.severity);
            mean_severity += entry.severity;
            count++;
        }
    }

    if (count > 0) {
        mean_severity /= count;
    }
}

int main() {
    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    string line;
    while (getline(infile, line)) {
        istringstream i(line);
        int operation;
        i >> operation;

        if (operation == 1) {
            string entry;
            getline(i, entry);
            size_t pos1 = entry.find(';');
            size_t pos2 = entry.find(';', pos1 + 1);
            long long timestamp = stoll(entry.substr(0, pos1));
            string log_type = entry.substr(pos1 + 1, pos2 - pos1 - 1);
            double severity = stod(entry.substr(pos2 + 1));
            add(timestamp, log_type, severity);
        } else if (operation == 2) {
            string log_type;
            i >> log_type;
            double min_severity, max_severity, mean_severity;
            int count;
            stats(0, numeric_limits<long long>::max(), log_type, false, min_severity, max_severity, mean_severity, count);
            if (count == 0) {
                outfile << "No output" << endl;
            } else {
                outfile << "Min: " << fixed << setprecision(6) << min_severity << ", Max: " << max_severity << ", Mean: " << mean_severity << endl;
            }
        } else if (operation == 3) {
            string temp;
            long long timestamp;
            i >> temp >> timestamp;
            double min_severity, max_severity, mean_severity;
            int count;
            if (temp == "BEFORE") {
                stats(timestamp, numeric_limits<long long>::min(), "", true, min_severity, max_severity, mean_severity, count);
            } else {
                stats(numeric_limits<long long>::max(), timestamp, "", true, min_severity, max_severity, mean_severity, count);
            }
            if (count == 0) {
                outfile << "No output" << endl;
            } else {
                outfile << "Min: " << fixed << setprecision(6) << min_severity << ", Max: " << max_severity << ", Mean: " << mean_severity << endl;
            }
        } else if (operation == 4) {
            string temp, log_type;
            long long timestamp;
            i >> temp >> log_type >> timestamp;
            double min_severity, max_severity, mean_severity;
            int count;
            if (temp == "BEFORE") {
                stats(timestamp, numeric_limits<long long>::min(), log_type, false, min_severity, max_severity, mean_severity, count);
            } else {
                stats(numeric_limits<long long>::max(), timestamp, log_type, false, min_severity, max_severity, mean_severity, count);
            }
            if (count == 0) {
                outfile << "No output" << endl;
            } else {
                outfile << "Min: " << fixed << setprecision(6) << min_severity << ", Max: " << max_severity << ", Mean: " << mean_severity << endl;
            }
        }
    }

    infile.close();
    outfile.close();

    return 0;
}
