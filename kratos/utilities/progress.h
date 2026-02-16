//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         BSD License
//                   Kratos default license: kratos/license.txt
//
//  Main authors:    Hoang-Giang Bui
//
//

#if !defined(KRATOS_PROGRESS_H_INCLUDED )
#define  KRATOS_PROGRESS_H_INCLUDED

#include <iostream>
#include <string>
#include <atomic>
#include <mutex>

namespace Kratos
{

class progress_display
{
public:
    explicit progress_display(unsigned long expected_count,
                              std::ostream& os = std::cout,
                              const std::string& s1 = "\n",
                              const std::string& s2 = "",
                              const std::string& s3 = "")
        : m_os(os), m_s1(s1), m_s2(s2), m_s3(s3), m_expected_count(expected_count)
    {
        restart(expected_count);
    }

    void restart(unsigned long expected_count) {
        m_count = 0;
        m_next_tic_count = 0;
        m_expected_count = expected_count;

        std::lock_guard<std::mutex> lock(m_mutex);
        m_os << m_s1 << "0%   10   20   30   40   50   60   70   80   90   100%\n"
             << m_s2 << "|----|----|----|----|----|----|----|----|----|----|"
             << std::endl << m_s3;
        if (m_expected_count == 0) m_expected_count = 1; // Prevent div by zero
    }

    unsigned long operator+=(unsigned long increment) {
        unsigned long current_count = (m_count += increment);
        display_tic(current_count);
        return current_count;
    }

    unsigned long operator++() { return operator+=(1); }
    unsigned long count() const { return m_count; }
    unsigned long expected_count() const { return m_expected_count; }

private:
    void display_tic(unsigned long current_count) {
        std::lock_guard<std::mutex> lock(m_mutex);

        // Don't do anything if we already finished printing the bar
        if (m_next_tic_count >= 50) return;

        // Calculate how many tics should be displayed based on current progress
        unsigned int tics_needed = static_cast<unsigned int>(
            (static_cast<double>(current_count) / m_expected_count) * 50
        );

        while (m_next_tic_count < tics_needed && m_next_tic_count < 50) {
            m_os << '*' << std::flush;
            m_next_tic_count++;

            // Terminate with newline when we hit the limit
            if (m_next_tic_count == 50) {
                m_os << std::endl;
            }
        }
    }

    std::ostream&     m_os;
    const std::string m_s1, m_s2, m_s3;
    std::atomic<unsigned long> m_count;
    unsigned long     m_expected_count;
    unsigned int      m_next_tic_count;
    std::mutex        m_mutex;
};

} // end namespace Kratos

#endif
