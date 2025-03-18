#ifndef HARL_HPP
# define HARL_HPP

class Harl
{
    public:
        Harl();
        ~Harl();

        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
        void    complain( std::string level );

    private:

}


#endif