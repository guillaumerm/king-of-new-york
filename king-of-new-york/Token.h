#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include <ostream>

using namespace std;
/**
 * @brief A class which regroups the behavior/action that a token would need to used in the game.
 */
class Token {
public:
	/** 
	 * Enum which contains the type of token.
	 */
	enum class Type { 
		Web,		/**< Web Token Type*/
		Jinx,		/**< Jinx Token Type*/
		Souvenir,	/**< Souvenir Token Type*/
		Carapace	/**< Carapace Token Type*/
	};

	/**
	 * Parameterless constructor
	 */
	Token();

	/**
	 * A constructor which init a Token with a name, description and type
	 * @param name name of the token
	 * @param description description of the token
	 * @param type type of the token
	 */
	Token(string name, string description, Type type);
	/**
	 * Obtain name of the token
	 * @return name of the token
	 */
	string getName() const;

	/**
	 * Obtain description of the token
	 * @return description of the token
	 */
	string getDescription() const;

	/**
	 * Obtain type of the token
	 * @return type of the tile
	 */
	Type getType() const;
private:
	Type type; /**< Type of the token */
	string name; /**< Name of the token */
	string description; /**< Description of the token */

	/**
	 * Sets the name of the token
	 * @param name name of the token
	 */
	void setName(string name);

	/**
	 * Sets the description of the token
	 * @param description description of the token
	 */
	void setDescription(string);

	/**
	 * Sets the type of the token
	 * @param type type of the token
	 */
	void setType(Type);
	friend ostream& operator<<(ostream&, Token const&);
};
#endif