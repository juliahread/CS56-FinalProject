Class Map {
private:
        std::list obstacle_list;
        std::list grappling_point_list;
        Point start_location;
        Point end_location;
public:
        void load_map(std::string);
}
