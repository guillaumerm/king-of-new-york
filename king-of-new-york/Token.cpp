#include "Token.h"

Token::Token(string name, string description, Token::Type type) {
	this->setName(name);
	this->setDescription(description);
	this->setType(type);
}

inline void Token::setName(string name) {
	this->name = name;
}

inline void Token::setDescription(string description) {
	this->description = description;
}

inline string Token::getName() const {
	return this->name;
}

inline string Token::getDescription() const {
	return this->description; 
}

inline void Token::setType(Token::Type type) {
	this->type = type;
}

inline Token::Type Token::getType() const{
	return this->type;
}


inline ostream& operator<<(ostream & strm, Token::Type const& type) {
	switch (type) {
	case Token::Type::Web:
		return strm << "Web";
		break;
	case Token::Type::Carapace:
		return strm << "Carapace";
		break;
	case Token::Type::Souvenir:
		return strm << "Souvenir";
		break;
	case Token::Type::Jinx:
		return strm << "Jinx";
		break;
	default:
		return strm << "Not a TokenType";
		break;
	}
}

ostream& operator<<(ostream &strm, Token const &token) {
	return strm << "Token(type:" << token.type << "name:" << token.name << ";description:" << token.description << ")";
}