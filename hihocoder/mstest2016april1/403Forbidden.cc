#include <iostream>
#include <vector>
#include <string>


using namespace std;

unsigned int masks[] = {
    0x00,
    0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff,
    0x80ff, 0xc0ff, 0xe0ff, 0xf0ff, 0xf8ff, 0xfcff, 0xfeff, 0xffff,
    0x80ffff, 0xc0ffff, 0xe0ffff, 0xf0ffff, 0xf8ffff, 0xfcffff, 0xfeffff, 0xffffff,
    0x80ffffff, 0xc0ffffff, 0xe0ffffff, 0xf0ffffff, 0xf8ffffff, 0xfcffffff, 0xfeffffff, 0xffffffff
};

union IPAddr {
    unsigned char byte[4];
    unsigned int value;
};

struct IPRule {
    IPAddr ip;
    unsigned int mask;
    bool allow;
    IPRule(): allow(false), mask(0xffffffff) { ip.value = 0x00; }
};


bool match(IPAddr &ip, IPRule &rule) {
    return (ip.value & rule.mask) == (rule.ip.value & rule.mask);
}

void setMask(IPRule &rule, int maskBits) {
    rule.mask = masks[maskBits];
}

bool isAllowed(vector<IPRule> &rules, IPAddr &ip) {
    for (int i = 0; i < rules.size(); i++) {
        if (match(ip, rules[i]))
            return rules[i].allow;
    }
    return true;
}

void parseIPWithMask(string &ipstr, IPRule &rule) {
    if (ipstr.empty()) return;

    size_t start = 0;
    size_t sep;

    sep = ipstr.find_first_of('.', start);
    rule.ip.byte[0] = std::stoi(ipstr.substr(start, sep - start));

    start = sep + 1;
    sep = ipstr.find_first_of('.', start);
    rule.ip.byte[1] = std::stoi(ipstr.substr(start, sep - start));

    start = sep + 1;
    sep = ipstr.find_first_of('.', start);
    rule.ip.byte[2] = std::stoi(ipstr.substr(start, sep - start));

    start = sep + 1;
    sep = ipstr.find_first_of('/', start);
    rule.ip.byte[3] = std::stoi(ipstr.substr(start, sep - start));

    int maskBits;
    if (sep == string::npos) {
        maskBits = 32;
    } else {
        maskBits = std::stoi(ipstr.substr(sep + 1));
    }
    setMask(rule, maskBits);
}

void parseIP(string &ipstr, IPAddr &ip) {
    if (ipstr.empty()) return;

    size_t start = 0;
    size_t sep;

    sep = ipstr.find_first_of('.', start);
    ip.byte[0] = std::stoi(ipstr.substr(start, sep - start));

    start = sep + 1;
    sep = ipstr.find_first_of('.', start);
    ip.byte[1] = std::stoi(ipstr.substr(start, sep - start));

    start = sep + 1;
    sep = ipstr.find_first_of('.', start);
    ip.byte[2] = std::stoi(ipstr.substr(start, sep - start));

    start = sep + 1;
    ip.byte[3] = std::stoi(ipstr.substr(start));
}

int main(int argc, char* argv[]) {
    int N, M;
    cin >> N >> M;
    vector<IPRule> rules(N);
    for (int i = 0; i < N; i++) {
        IPRule rule;
        string cmd;
        string ipstr;
        cin >> cmd >> ipstr;

        if (cmd.compare("allow") == 0)
            rule.allow = true;
        else
            rule.allow = false;

        parseIPWithMask(ipstr, rule);
        rules[i] = rule;
    }

    for (int i = 0; i < M; i++) {
        string ipstr;
        IPAddr ip;
        cin >> ipstr;
        parseIP(ipstr, ip);

        if (isAllowed(rules, ip))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;

}



