# How to Run

## Setting Up Raylib

Follow the steps below to download and set up Raylib.

### Step 1: Download Raylib

First, download Raylib using the following link: [Raylib on GitHub](https://github.com/microsoft/vcpkg).

### Step 2: Open Raylib Directory

Navigate to the directory where Raylib is installed. Right-click on the folder and select "Open in Terminal."

### Step 3: Install Raylib

In the terminal, execute the following commands:

1. Bootstrap vcpkg by running:
   ```sh
   bootstrap-vcpkg.bat
   ```
2. Integrate vcpkg into your system:
   ```sh
   vcpkg integrate install
   ```
3. Install Raylib for x64 Windows:
   ```sh
   vcpkg install raylib:x64-windows
   ```

Now everything should be set.
