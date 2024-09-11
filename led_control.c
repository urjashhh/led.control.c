#include <stdio.h>
#include <stdint.h>

// Define the LEDSettings structure
typedef struct {
    uint8_t state;      // ON/OFF state of the LED (1 for ON, 0 for OFF)
    uint8_t brightness; // Brightness level (0 to 255)
    uint32_t color;     // Color encoded in RGB format (0xRRGGBB)
} LEDSettings;

// Define the LEDGroup structure
typedef struct {
    LEDSettings singleLED; // Individual LED settings
    uint8_t groupState;    // Collective state of the group (1 for all ON, 0 for all OFF)
    uint8_t groupBrightness; // Collective brightness adjustment for the group
} LEDGroup;

// Function to initialize the LEDGroup structure
void initLEDGroup(LEDGroup *group) {
    if (group == NULL) return;
    
    // Initialize single LED settings
    group->singleLED.state = 0;
    group->singleLED.brightness = 0;
    group->singleLED.color = 0x000000; // Default color (black)

    // Initialize group settings
    group->groupState = 0;
    group->groupBrightness = 0;
}

// Function to update LEDGroup settings
void updateLEDGroupSettings(LEDGroup *group, uint8_t groupState, uint8_t groupBrightness, uint8_t state, uint8_t brightness, uint32_t color) {
    if (group == NULL) return;

    // Update single LED settings
    group->singleLED.state = state;
    group->singleLED.brightness = brightness;
    group->singleLED.color = color;

    // Update group settings
    group->groupState = groupState;
    group->groupBrightness = groupBrightness;
}

// Function to display LEDGroup status
void displayLEDGroupStatus(const LEDGroup *group) {
    if (group == NULL) return;

    // Display individual LED settings
    printf("LED Settings:\n");
    printf("  State: %s\n", group->singleLED.state ? "ON" : "OFF");
    printf("  Brightness: %u\n", group->singleLED.brightness);
    printf("  Color: #%06X\n", group->singleLED.color);

    // Display group settings
    printf("Group Settings:\n");
    printf("  Group State: %s\n", group->groupState ? "All ON" : "All OFF");
    printf("  Group Brightness: %u\n", group->groupBrightness);
}

// Main function to demonstrate the functionality
int main() {
    LEDGroup myLEDGroup;

    // Initialize the LED group
    initLEDGroup(&myLEDGroup);

    // Update LED group settings
    updateLEDGroupSettings(&myLEDGroup, 1, 128, 1, 255, 0xFF5733); // Example values

    // Display LED group status
    displayLEDGroupStatus(&myLEDGroup);

    return 0;
}
