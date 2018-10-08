#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include <ostream>

using namespace std;

class Token {
public:
	/** Enum which contains the type of token.
	 */
	enum class Type { 
		Web,		/**< Web Token Type*/
		Jinx,		/**< Jinx Token Type*/
		Souvenir,	/**< Souvenir Token Type*/
		Carapace	/**< Carapace Token Type*/
	};
	Token();
	Token(string, string, Type);
	string getName() const;			//! Obtain name of the token
	string getDescription() const;	//! Obtain description of the token
	Type getType() const;			//! Obtain type of the token
private:
	Type type;
	string name;
	string description;
	void setName(string);
	void setDescription(string);
	void setType(Type);
	friend ostream& operator<<(ostream&, Token const&);
};
#endif