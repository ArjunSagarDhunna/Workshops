
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <string>

namespace sdds {
   class Book
   {
      std::string m_author{};
      std::string m_title{};
      std::string m_country{};
      size_t m_year{};
      double m_price{};
      std::string m_description{};
      std::string& trim(std::string& str);

    public:
      Book();
      Book(const std::string& strBook);
      const std::string& title() const;
      const std::string& country() const;
      const size_t& year() const;
      double& price();
      friend std::ostream& operator<<(std::ostream&, const Book&);
      template <typename T> void fixSpelling(T& spellChecker) {
         spellChecker(m_description);
      }
   };

} // namespace sdds

#endif //! SDDS_BOOK_H
