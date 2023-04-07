#include "ShowLines.h"

ShowLines::ShowLines(Graph &graph) : Action(graph) {};

void ShowLines::draw(vector<Line> data, int page, int npages) {
    system("clear");
    cout << "\033[0m";
    cout << "─────────────────────────────────────────────────────────────────────────────────────────────────────"
         << endl;
    cout << "│\033[40m                                                  Page(" << page + 1 << "/" << npages << ")";
    for (int i = 0; i < 8 - to_string(page + 1).length() - to_string(npages).length(); i++)
        cout << ' ';
    cout << "                                  \033[0m│" << endl;
    cout
            << "│\033[40m───────────────────────────────────────────────────────────────────────────────────────────────────\033[0m│"
            << endl;
    cout
            << "│\033[40m Station 1                            │ Station 2                           │ Capacity │ Service   \033[0m│"
            << endl;
    cout
            << "│\033[40m───────────────────────────────────────────────────────────────────────────────────────────────────\033[0m│"
            << endl;
    for (int i = 10 * page; i < 10 * page + 10; i++) {
        if (i == data.size())
            break;

        data[i].print(i);

    }

    cout
            << "│\033[40m───────────────────────────────────────────────────────────────────────────────────────────────────\033[0m│"
            << endl;
    cout
            << "│\033[40m             [n]Next                      [p]Previous                      [q]Go Back              \033[0m│"
            << endl;
    cout
            << "|\033[40m───────────────────────────────────────────────────────────────────────────────────────────────────\033[0m|"
            << endl;
};

void ShowLines::execute() {
    vector<Line> lines;
    for (auto line: graph->getLineVector()) {
        lines.push_back(*line);
    }
    paginationController(lines);
}

void ShowLines::paginationController(vector<Line> data) {
    /* due to the template this functions had to be written here as if it was on the cpp it would not recognize the template*/
    int page = 0;
    while (page >= 0 and page < (float) data.size() / 10.0) {
        string option;
        draw(data, page, ceil((float) data.size() / 10.0));
        bool cond = true;
        while (cond) {
            cout << endl
                 << "\033[32mChoose an option[n/p/q] or the number of the page you would want to go[1-"
                 << ceil((float) data.size() / 10.0) << "]: ";
            cond = true;
            cin >> option;

            if (option.length() == 1) {
                option = ::toupper(option[0]);
                switch (option[0]) {
                    case 'N':
                        page++;
                        cond = false;
                        break;
                    case 'P':
                        page--;
                        cond = false;
                        break;
                    case 'Q':
                        page = -1;
                        cond = false;
                        break;
                    default:
                        cond = true;
                }
            }
            if (cond) {
                int test;
                try {
                    cond = false;
                    test = stoi(option);
                }
                catch (invalid_argument) {
                    cond = true;
                }
                if (!cond) {
                    cond = true;
                    if (to_string(test).length() == option.length()) {
                        if (test > 0 and test <= ceil((float) data.size() / 10.0)) {
                            page = test - 1;
                            cond = false;
                        }
                    }
                }
            }
            if (cond)
                cout << "\033[31mInvalid input! Please enter a valid input: \033[0m";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
};
