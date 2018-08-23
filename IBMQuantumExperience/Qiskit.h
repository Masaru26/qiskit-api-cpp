// Copyright by Benjamin Luxbacher
#ifndef _QISKIT_H_
#define _QISKIT_H_

#include <string>
#include <vector>
#include <algorithm>

namespace Qiskit
{
    /*char* GetJobUrl(? config, ? hub, ? group, ? project);
    char* GetBackendStatsUrl(? config, ? hub, ? backendType);
    char* GetBackendUrl(? config, ? hub, ? group, ? project);
    ? [] CleanQObjectResult(job);*/

    const std::string CLIENT_APPLICATION = "qiskit-api-cpp";

    std::vector<std::string> split(std::string_view content, std::string_view delimiter)
    {
        std::vector<std::string> result;
        auto prev_pos = content.begin();
        auto next_pos = std::search(prev_pos, content.end(), delimiter.begin(), delimiter.end());

        while (next_pos != content.end())
        {
            result.emplace_back(prev_pos, next_pos);
            prev_pos = next_pos + delimiter.size();
            next_pos = std::search(prev_pos, content.end(), delimiter.begin(), delimiter.end());
        }

        if (prev_pos != content.end())
        {
            result.emplace_back(prev_pos, content.end());
        }

        return result;
    }
}

#endif