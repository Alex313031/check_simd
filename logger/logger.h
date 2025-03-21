#ifndef LOGGER_LOGGER_H_
#define LOGGER_LOGGER_H_

#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

#include "base/export.h"

#ifndef NOTREACHED
#define NOTREACHED() KILL()
#endif
#ifndef NOTREACHABLE
#define NOTREACHABLE NOTREACHED
#endif

// Kill immediately
inline __attribute__((__always_inline__)) int KILL() {
  //__builtin_unreachable();
  static constexpr int a = 1;
  static constexpr int b = 0;
  return a / b;
}

// Enum to represent log levels
enum LogLevel { INFO, WARN, ERROR, NL };

// Length of timestamp
char timestamp[20];

// Our Log:: class for check_simd to consume
class Log {
 public:
  // Constructor: 
  // Logs a message with a given log level
  EXPORT Log(const std::string& filename);

  // Destructor: Closes the log file
  EXPORT ~Log();

  //
  void getTime();

  // Log severity types
  // Creates the entries as well
  EXPORT void info(const std::string& info_message);
  EXPORT void warn(const std::string& warn_message);
  EXPORT void error(const std::string& error_message);
  // NewLine function
  EXPORT void nl(LogLevel level);

 private:
  // File stream for the log file
  std::ofstream logFile;

  // Creates / opens the log file in append mode
  // with a name supplied during initialization.
  void init(const std::string& filename);

  // Passed to std:: cout or cerr
  std::string logOutput;

  // File the log to the logfile
  void filelog(std::string logOutput);

  // Converts log level to a string for output
  const std::string levelToString(LogLevel level);
}; // Class Log

#endif // LOGGER_LOGGER_H_
