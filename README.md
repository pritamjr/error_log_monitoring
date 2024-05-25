# error_log_monitoring

"**error_log_monitoring.cpp**"- This C++ program can monitor and analyze error logs. It adds log entries, calculates statistical metrics based on specific criteria, and generates outputs. The program reads commands and data from an input file and writes the results to an output file.


"**Dockerfile**"- The Dockerfile sets up a container to compile and run the error_log_monitoring.cpp program irrespective of the environment.



"**input.txt**"- This file contains commands and data for the error_log_monitoring program. Each line represents a command:

1 TIMESTAMP;LOG_TYPE;SEVERITY: Add a new log entry.

2 LOG_TYPE: Compute and print the min, max, and mean severity for the specified log type.

3 BEFORE TIMESTAMP: Compute and print the min, max, and mean severity for all entries before the specified timestamp.

3 AFTER TIMESTAMP: Compute and print the min, max, and mean severity for all entries after the specified timestamp.

4 BEFORE LOG_TYPE TIMESTAMP: Compute and print the min, max, and mean severity for all entries of the specified log type before the specified timestamp.

4 AFTER LOG_TYPE TIMESTAMP: Compute and print the min, max, and mean severity for all entries of the specified log type after the specified timestamp.





"output.txt"- This file contains the output of the error_log_monitoring program. It displays the results of the statistical calculations or "No output" if there are no entries matching the criteria.




# Running Instructions

Build the Docker Image: **docker build -t error_log_monitoring** .

Run the Docker Container: **docker run --name error_log_monitoring_container error_log_monitoring**

Copy the Output File from the Container to the Host Machine: **docker cp error_log_monitoring_container:/usr/src/app/output.txt .**

