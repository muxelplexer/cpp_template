#pragma once
#include <cstddef>
#include <format>
#include <ranges>
#include <string>
#include <string_view>
#include <vector>

class event
{
public:
    constexpr event(const std::size_t idx, const std::string_view title, const std::string_view promoter, const std::vector<std::string>& artists)
        : m_ID{idx}, m_Title{title}, m_Promoter{promoter}, m_Artists{std::move(artists)}
    {

    }

    [[nodiscard]] inline constexpr size_t id() const { return this->m_ID; };
    [[nodiscard]] inline constexpr std::string_view title() const { return this->m_Title; };
    [[nodiscard]] inline constexpr std::string_view promoter() const { return this->m_Title; };
    [[nodiscard]] inline constexpr std::vector<std::string_view> artists() const
    {
        auto view = std::views::transform(this->m_Artists, [](const std::string& str){
            return std::string_view(str);
        });

        return {view.begin(), view.end()};
    };

    [[nodiscard]] inline constexpr std::string to_string() const
    {
        return std::format("[{}] {} - {}", m_ID, m_Title, m_Promoter);
    }

private:
    std::size_t m_ID{0};
    std::string m_Title{""};
    std::string m_Promoter{""};
    std::vector<std::string> m_Artists{};
};