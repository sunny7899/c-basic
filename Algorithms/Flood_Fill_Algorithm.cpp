#include <iostream>
#include <vector>

using namespace std;

void floodFillUtil(vector<vector<int>>& image, int x, int y, int newColor, int oldColor) {
    // Boundary check
    if (x < 0 || x >= image.size() || y < 0 || y >= image[0].size())
        return;
    
    // Return if the current pixel is not of the old color
    if (image[x][y] != oldColor)
        return;

    // Change the color of the current pixel
    image[x][y] = newColor;

    // Recur for the 4 adjacent pixels
    floodFillUtil(image, x + 1, y, newColor, oldColor); // down
    floodFillUtil(image, x - 1, y, newColor, oldColor); // up
    floodFillUtil(image, x, y + 1, newColor, oldColor); // right
    floodFillUtil(image, x, y - 1, newColor, oldColor); // left
}

void floodFill(vector<vector<int>>& image, int startX, int startY, int newColor) {
    int oldColor = image[startX][startY];
    
    // Check if the starting pixel already has the new color
    if (oldColor == newColor) return;
    
    floodFillUtil(image, startX, startY, newColor, oldColor);
}

int main() {
    int rows, cols, startX, startY, newColor;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> image(rows, vector<int>(cols));
    cout << "Enter image pixels (row by row):" << endl;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            cin >> image[i][j];

    cout << "Enter starting pixel (x y) and new color: ";
    cin >> startX >> startY >> newColor;

    floodFill(image, startX, startY, newColor);

    cout << "Modified image after flood fill:" << endl;
    for (const auto& row : image) {
        for (int pixel : row)
            cout << pixel << " ";
        cout << endl;
    }

    return 0;
}
