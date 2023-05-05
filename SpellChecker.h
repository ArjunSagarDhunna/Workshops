

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <string>

namespace sdds {
   constexpr size_t SIZE = 6;

   class SpellChecker
   {
      std::string m_badWords[SIZE]{};
      std::string m_goodWords[SIZE]{};
      int m_replaced[SIZE]{};

    public:
      SpellChecker();
      SpellChecker(const char* filename);
      void operator()(std::string& text);
      void showStatistics(std::ostream& os) const;
   };
} // namespace sdds

#endif //! SDDS_SPELLCHECKER_H
