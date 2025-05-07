#include <iostream>
#include <string>
using namespace std;

// Function to give response based on user input
void chatbotResponse(const string& userInput) {
    if (userInput == "hi" || userInput == "hello") {
        cout << "Chatbot: Hello! How can I help you today?\n";
    } 
    else if (userInput == "price" || userInput == "cost") {
        cout << "Chatbot: Our products range from $10 to $100. Do you want more details?\n";
    } 
    else if (userInput == "bye" || userInput == "exit") {
        cout << "Chatbot: Thank you for visiting. Have a great day!\n";
    } 
    else if (userInput == "help") {
        cout << "Chatbot: You can ask me about product prices, availability, or say 'bye' to end chat.\n";
    }
    else {
        cout << "Chatbot: I'm sorry, I didn't understand that. Type 'help' to see what you can ask.\n";
    }
}

int main() {
    string userInput;
    cout << "Welcome to Customer Support Chatbot!\n";
    cout << "Type 'help' to see available options.\n";

    while (true) {
        cout << "\nYou: ";
        getline(cin, userInput);

        // Convert userInput to lowercase for simplicity (optional)
        for (auto& c : userInput) c = tolower(c);

        if (userInput == "bye" || userInput == "exit") {
            chatbotResponse(userInput);
            break;
        }

        chatbotResponse(userInput);
    }

    return 0;
}
