#include <Wire.h>
#include <rgb_lcd.h>

rgb_lcd lcd;

void setup() {
  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  // Initialize random number generator with an unconnected analog pin
  randomSeed(analogRead(0));

  // Initial message
  lcd.setRGB(0, 255, 0); // Set the backlight color to green
  lcd.print("Getting rarity...");
}

void loop() {
  // Choose a rarity randomly
  int rarityIndex = random(0, 4); // Generates a random number between 0 and 3
  String rarity;
  switch (rarityIndex) {
    case 0:
      rarity = "Legendary";
      lcd.setRGB(255, 0, 0); // Red for legendary
      break;
    case 1:
      rarity = "Epic";
      lcd.setRGB(128, 0, 128); // Purple for epic
      break;
    case 2:
      rarity = "Rare";
      lcd.setRGB(0, 0, 255); // Blue for rare
      break;
    case 3:
      rarity = "Common";
      lcd.setRGB(255, 255, 255); // White for common
      break;
  }

  // Clear the LCD and print the winning message
  lcd.clear();
  lcd.print("You've won a");
  lcd.setCursor(0, 1); // Move cursor to the second line
  lcd.print("free: " + rarity + "!");

  // Wait for a bit before showing the next rarity
  delay(5000); // Delay for 5 seconds
}
