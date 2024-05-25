# Use an official GCC runtime as a parent image
FROM gcc:latest

# Set the working directory inside the container
WORKDIR /usr/src/app

# Copy the current directory contents into the container at /usr/src/app
COPY . .

# Compile the program
RUN g++ -o error_log_monitoring error_log_monitoring.cpp

# Run the executable
CMD ["./error_log_monitoring"]
