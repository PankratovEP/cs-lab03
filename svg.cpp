#include <iostream>
#include <vector>
using namespace std;


void
svg_begin(double width, double height)
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}


void
svg_end()
{
    cout << "</svg>\n";
}

void
svg_text(double left, double baseline, string text)
{

    cout << "<text x='" << left << "' y='"<< baseline <<"'>"<< text <<"</text>\n";

}

void svg_rect(double x, double y, double width, double height)
{
    cout << "<rect x='"<< x <<"' y='"<< y <<"' width='"<< width <<"' height='"<< height <<"'/>\n";
}

void svg_rect(double x, double y, double width, double height, string stroke, string fill )
{
    cout << "<rect x='"<< x <<"' y='"<< y <<"' width='"<< width <<"' height='"<< height <<"' stroke='"<<stroke<<"' fill='"<< fill<<"'/>\n";
}

void svg_rect(double x, double y, double width, double height, string stroke, string fill, double fill_opacity )
{
    cout << "<rect x='"<< x <<"' y='"<< y <<"' width='"<< width <<"' height='"<< height <<"' stroke='"<<stroke<<"' fill='"<<
         fill<<"' fill-opacity ='"<< fill_opacity <<"'/>\n";
}

double
opacity_factor (size_t bin, size_t max_count)
{
    double opacity = (double)bin / max_count;
    return opacity;
}

void
show_histogram_svg(const vector<size_t>& bins)
{
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;
    const auto MAX_COUNT = 34;

    double top = 0;
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    size_t count;
    size_t max_count = bins[0];
    for (size_t bin : bins)
    {
        if (bin > max_count)
        {
            max_count = bin;
        }
    }

    if (max_count > MAX_COUNT)
    {

        const double scaling_factor = (double)MAX_COUNT / max_count;

        for (size_t bin : bins)
        {
            auto height = (size_t)(bin * scaling_factor);
            const double bin_width = BLOCK_WIDTH * height;
            svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
            svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "blue", "#ff2233", opacity_factor(bin, max_count));
            top += BIN_HEIGHT;

        }

        svg_end();
    }
    else
    {
        for (size_t bin : bins)
        {

            const double bin_width = BLOCK_WIDTH * bin;
            svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
            svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "blue", "#aaffaa", opacity_factor(bin, max_count));
            top += BIN_HEIGHT;

        }
        svg_end();

    }

}


//void
//show_histogram_svg17(const vector<size_t>& bins, size_t bin_count)
//{
//    const auto IMAGE_WIDTH = 400;
//    const auto IMAGE_HEIGHT = 300;
//    const auto TEXT_LEFT = 20;
//    const auto TEXT_BASELINE = 20;
//    const auto TEXT_WIDTH = 50;
//    const auto BIN_HEIGHT = 30;
//    const auto BLOCK_WIDTH = 10;
//    const auto MAX_COUNT = 34;
//
//    double top = 0;
//    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
//    size_t count;
//    size_t max_count = bins[0];
//    for (int i = 1; i < bin_count; i++)
//    {
//        if (bins[i] > max_count)
//        {
//            max_count = bins[i];
//        }
//    }
//
//    if (max_count > MAX_COUNT)
//    {
//
//        const double scaling_factor = (double)MAX_COUNT / max_count;
//
//
//
//        for (size_t bin : bins)
//        {
//            auto height = (size_t)(bin * scaling_factor);
//            const double bin_width = BLOCK_WIDTH * height;
//            //double opacity_factor = (double)bin / max_count;
//            svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
//            svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "blue", "#ff2233", opacity_factor(bin, max_count));
//            top += BIN_HEIGHT;
//
//        }
//
//        svg_end();
//    }
//    else
//    {
//        for (size_t bin : bins)
//        {
//
//            const double bin_width = BLOCK_WIDTH * bin;
//           // double opacity_factor = (double)bin / max_count;
//            svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
//            svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "blue", "#aaffaa", opacity_factor(bin, max_count));
//            top += BIN_HEIGHT;
//
//        }
//        svg_end();
//
//    }

//}
