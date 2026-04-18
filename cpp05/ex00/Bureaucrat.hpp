#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <exception>
# define MAX 1
# define MIN 150

class Bureaucrat{
    private:
        const std::string name;
        long long grade;

    public:
        Bureaucrat();
        Bureaucrat(Bureaucrat& other);
        Bureaucrat& operator=(Bureaucrat& other);
        ~Bureaucrat();
        Bureaucrat(const std::string name, const long long grade);

        std::string getName() const;
        int getGrade() const;
        int incrementGrade();
        int decrementGrade();

        class GradeTooHighException : public std::exception{
            public:
                virtual const char* what() const throw() {
                    return "Grade is too high! (Limit: 1)";
                }
        };
        class GradeTooLowException : public std::exception{
            public:
                virtual const char* what() const throw() {
                    return "Grade is too low! (Limit: 150)";
                }
        };
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& br);

#endif