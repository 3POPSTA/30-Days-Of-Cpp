#include "task_manager.hpp"
#include <fstream>
#include <algorithm>
#include <iostream>

TaskManager::TaskManager(std::string filename) : storage_filename(std::move(filename)) {
    load_from_disk();
}

TaskManager::~TaskManager() {
    save_to_disk();
}

void TaskManager::save_to_disk() const {
    std::ofstream out(storage_filename);
    if (!out) return;
    for (const auto& task : tasks) {
        out << task.serialize() << "\n";
    }
}

void TaskManager::load_from_disk() {
    std::ifstream in(storage_filename);
    if (!in) return;
    tasks.clear();
    std::string line;
    int max_id = 0;
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        try {
            Task t = Task::deserialize(line);
            if (t.get_id() > max_id) max_id = t.get_id();
            tasks.push_back(std::move(t));
        } catch (...) {}
    }
    next_id = max_id + 1;
}

void TaskManager::add_task(const std::string& title) {
    tasks.emplace_back(next_id++, title);
    save_to_disk();
    std::cout << "Added task successfully!\n";
}

bool TaskManager::complete_task(int id) {
    auto it = std::find_if(tasks.begin(), tasks.end(), [id](const Task& t) {
        return t.get_id() == id;
    });
    if (it != tasks.end()) {
        it->mark_completed();
        save_to_disk();
        return true;
    }
    return false;
}

bool TaskManager::delete_task(int id) {
    auto it = std::remove_if(tasks.begin(), tasks.end(), [id](const Task& t) {
        return t.get_id() == id;
    });
    if (it != tasks.end()) {
        tasks.erase(it, tasks.end());
        save_to_disk();
        return true;
    }
    return false;
}

void TaskManager::list_all_tasks() const {
    std::cout << "\n--- Task Management List (" << tasks.size() << ") ---\n";
    if (tasks.empty()) {
        std::cout << "(No tasks found)\n";
        return;
    }
    for (const auto& t : tasks) {
        std::cout << t.to_string() << "\n";
    }
    std::cout << "\n";
}

size_t TaskManager::count() const noexcept {
    return tasks.size();
}
