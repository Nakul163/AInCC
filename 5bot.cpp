#include <iostream>
#include <string>
#include <algorithm>

std::string toLowerCase(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main() {
    std::string userInput;

    std::cout << "Hello! I'm your friendly chatbot. How can I assist you today?" << std::endl;

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, userInput);
        userInput = toLowerCase(userInput);

        if (userInput == "hello" || userInput == "hi") {
            std::cout << "Hi there! How can I help you?" << std::endl;
        } else if (userInput == "how are you") {
            std::cout << "I'm just a computer program, so I don't have feelings, but thanks for asking!" << std::endl;
        } else if (userInput == "bye" || userInput == "exit") {
            std::cout << "Goodbye! Have a great day!" << std::endl;
            break;
        } else if (userInput == "what is your name") {
            std::cout << "I am a chatbot. You can call me whatever you like!" << std::endl;
        } else if (userInput == "what can you do") {
            std::cout << "I can help you with various tasks such as answering questions, providing information, and more. Just ask!" << std::endl;
        } else if (userInput == "how can I contact support") {
            std::cout << "You can contact our support team via email at support@example.com or by phone at +123456789." << std::endl;
        } else if (userInput == "what are your working hours") {
            std::cout << "Our working hours are from 9:00 AM to 5:00 PM, Monday to Friday." << std::endl;
        } else if (userInput == "do you have any promotions or discounts") {
            std::cout << "Yes, we often have promotions and discounts. You can check our website or subscribe to our newsletter for updates." << std::endl;
        } else if (userInput == "how do I reset my password") {
            std::cout << "You can reset your password by visiting our website and clicking on the 'Forgot Password' link." << std::endl;
        } else if (userInput == "where can I find product manuals") {
            std::cout << "Product manuals can be found on our website under the 'Support' or 'Resources' section." << std::endl;
        } else if (userInput == "what payment methods do you accept") {
            std::cout << "We accept various payment methods including credit/debit cards, PayPal, and bank transfers." << std::endl;
        } else if (userInput == "how do I return a product") {
            std::cout << "You can initiate a product return by contacting our support team or by filling out the return form on our website." << std::endl;
        } else if (userInput == "what is your privacy policy") {
            std::cout << "You can view our privacy policy on our website under the 'Privacy Policy' section." << std::endl;
        } else {
            std::cout << "I'm sorry, I didn't understand that. Can you please repeat or ask something else?" << std::endl;
        }
    }

    return 0;
}
