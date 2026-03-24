#include "task.hpp"
#include <sstream>

Task::Task(int id, std::string title, bool completed)
    : id(id), title(std::move(title)), completed(completed) {}

int Task::get_id() const noexcept { return id; }
const std::string& Task::get_title() const noexcept { return title; }
bool Task::is_completed() const noexcept { return completed; }

void Task::mark_completed() noexcept { completed = true; }

std::string Task::to_string() const {
    std::ostringstream oss;
    oss << "[" << (completed ? "X" : " ") << "] #" << id << ": " << title;
    return oss.str();
}

std::string Task::serialize() const {
    return std::to_string(id) + "|" + (completed ? "1" : "0") + "|" + title;
}

Task Task::deserialize(const std::string& line) {
    std::stringstream ss(line);
    std::string id_str, comp_str, title_str;
    std::getline(ss, id_str, '|');
    std::getline(ss, comp_str, '|');
    std::getline(ss, title_str);

    int id = std::stoi(id_str);
    bool completed = (comp_str == "1");
    return Task(id, title_str, completed);
}
