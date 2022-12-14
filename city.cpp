#include "city.h"

city::city(const city& other) : name{ other.name }, parentCountry{ other.parentCountry } 
{
    if(!other.foodItems.empty())
        for(int i = 0; i < static_cast<int>(other.foodItems.size()); i++)
            this->foodItems.push_back(new food(other.foodItems[i]->getName(), other.foodItems[i]->getPrice()));
}

city::~city(){
    for(auto f : foodItems)
        delete f;
}

QString city::getName() const 
{
    return name;
}

QString city::getParentCountry() const
{
        return parentCountry;
}

food city::getFood(const int index) const
{
        return *foodItems.at(index);
}

std::vector<food*>& city::getFoodRef() {
    return foodItems;
}

void city::setName(const QString name)
{
        this->name = name;
}

void city::setParentCountry(const QString parentCountry)
{
        this->parentCountry = parentCountry;
}

void city::addFoodItem(food* foodItem)
{
        foodItems.push_back(foodItem);
}

int city::getNumFood() const {
    return static_cast<int>(foodItems.size());
}
