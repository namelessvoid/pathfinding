#ifndef SQUARE_HPP
#define SQUARE_HPP

class Square
{
	public:
		enum Content
		{
			EC_EMPTY,
			EC_WALL,
			EC_START,
			EC_END
		};

		Square();

		void setContent(Content content);
		Content getContent();
	private:
		Content content;
};

#endif