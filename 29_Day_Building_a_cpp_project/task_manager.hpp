#pragma once
#include "task.hpp"
#include <vector>
#include <string>

class TaskManager {
private:
    std::vector<Task> tasks;
    std::string storage_filename;
    int next_id{1};

    void save_to_disk() const;
    void load_from_disk();

public:
    explicit TaskManager(std::string filename);
    ~TaskManager();

    void add_task(const std::string& title);
    bool complete_task(int id);
    bool delete_task(int id);
    void list_all_tasks() const;
    size_t count() const noexcept;
};
