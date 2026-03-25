#pragma once
#include <string>
#include <iostream>

class Task {
private:
    int id;
    std::string title;
    bool completed;

public:
    Task(int id, std::string title, bool completed = false);

    int get_id() const noexcept;
    const std::string& get_title() const noexcept;
    bool is_completed() const noexcept;

    void mark_completed() noexcept;
    std::string to_string() const;

    // Serialization format: id|completed|title
    std::string serialize() const;
    static Task deserialize(const std::string& line);
};
