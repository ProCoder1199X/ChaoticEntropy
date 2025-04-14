import math
import random
import time

# Try importing sensor modules (simulate if not available)
try:
    import Adafruit_DHT
    SENSOR_AVAILABLE = True
except ImportError:
    SENSOR_AVAILABLE = False

# Get current system time (adds entropy)
def get_entropy_time():
    return time.time()

# Get temperature from sensor or manual input
def get_temperature():
    if SENSOR_AVAILABLE:
        sensor = Adafruit_DHT.DHT11
        pin = 4  # You can modify according to your setup
        humidity, temperature = Adafruit_DHT.read_retry(sensor, pin)
        return temperature if temperature else float(input("Temp sensor error. Enter temp manually: "))
    else:
        return float(input("Enter a temperature value (e.g., 27.5): "))

# Get manual brain-generated number
def get_user_seed():
    return int(input("Enter a random number from your thoughts (1-99): "))

# Complex entropy function (can be evolved)
def generate_entropy_value(temp, user_input, entropy_time):
    try:
        value = (temp + user_input**2) * abs(math.sin(entropy_time)) / (entropy_time % 7 + 1)
        value += (math.sqrt(user_input + temp) * 1.618)  # golden ratio spice
        return value
    except:
        return random.random() * 10000  # fallback
        

# Generate random coordinates
def generate_coordinates(entropy):
    # Latitude: -90 to +90, Longitude: -180 to +180
    lat = ((entropy * random.random()) % 180) - 90
    lon = ((entropy / (random.random() + 0.01)) % 360) - 180
    return round(lat, 6), round(lon, 6)

# Main Function
def main():
    print("=== ChaoticEntropy: DEG v1 ===")
    temp = get_temperature()
    user_input = get_user_seed()
    entropy_time = get_entropy_time()

    entropy = generate_entropy_value(temp, user_input, entropy_time)
    print(f"\n[+] Entropy Generated: {entropy}")

    lat, lon = generate_coordinates(entropy)
    print(f"[+] Random Coordinates => Latitude: {lat}, Longitude: {lon}")

    print(f"[+] Random Number (from entropy): {round(entropy % 1000000, 6)}")

if __name__ == "__main__":
    main()
