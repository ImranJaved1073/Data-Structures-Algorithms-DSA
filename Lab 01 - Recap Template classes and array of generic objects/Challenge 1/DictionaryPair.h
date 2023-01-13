#ifndef DICTIONARYPAIR_H
#define DICTIONARYPAIR_H

template <typename T, typename U>
class DictionaryPair
{
	T key;
	U value;
public:
	DictionaryPair()
	{
		key = T();
		value = U();
	}
	DictionaryPair(T key, U value)
	{
		this->key = key;
		this->value = value;
	}
	void setKey(T key)
	{
		this->key = key;
	}
	void setValue(U value)
	{
		this->value = value;
	}
	T getKey()
	{
		return key;
	}
	U getValue()
	{
		return value;
	}
};

#endif // !DICTIONARY_PAIR