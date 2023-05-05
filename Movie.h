
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <string>

namespace sdds {
   class Movie
   {
      std::string m_title{};
      size_t m_year{};
      std::string m_description{};
      std::string& trim(std::string& str);

    public:
      Movie();
      Movie(const std::string& strMovie);
      const std::string& title() const;
      template <typename T> void fixSpelling(T& spellChecker) {
         spellChecker(m_description);
         spellChecker(m_title);
      }
      friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
   };
} // namespace sdds

#endif //! SDDS_MOVIE_H
