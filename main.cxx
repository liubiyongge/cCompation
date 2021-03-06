#include <iostream>
#include <assert.h>
#include "rocksdb/db.h"
#include "spdlog/spdlog.h"
#include "spdlog/async.h"
#include "spdlog/sinks/basic_file_sink.h"
using namespace std;

int main() {
    //open a log
    auto logfile = spdlog::basic_logger_mt<spdlog::async_factory>("async_file_logger", "logs/log.txt");
    logfile->set_pattern("[%H:%M:%S %z] [thread %t] [%s %#] [%l] %v");
#if defined(PRODUCTION)
    logfile->set_level(spdlog::level::off);
#else
    logfile->set_level(spdlog::level::trace);
#endif
    spdlog::set_default_logger(logfile);

    rocksdb::DB* db;
    rocksdb::Options options;
    options.create_if_missing = true;
    
    // open a database with a name which corresponds to a file system directory
    rocksdb::Status status = rocksdb::DB::Open(options, "/tmp/testdb", &db);
    // check status
    if (!status.ok()) cerr << status.ToString() << endl;
    
    // Slice type can (should) be used in place of std::string for key-value
    rocksdb::Slice key = "foo";
    std::string value1 = "bar";
    
    // modify/query the database
    status = db->Put(rocksdb::WriteOptions(), key, value1);
    assert(status.ok());
    std::string value2;
    status = db->Get(rocksdb::ReadOptions(), key, &value2);
    assert(status.ok() && value1 == value2);
    status = db->Delete(rocksdb::WriteOptions(), key);
    assert(status.ok());
    status = db->Get(rocksdb::ReadOptions(), key, &value2);
    assert(status.IsNotFound());
    SPDLOG_INFO("value is {}.\n", value2);
    // close the database
    delete db;
    
    return 0;
}
