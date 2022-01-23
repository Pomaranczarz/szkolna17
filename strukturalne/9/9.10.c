#include <stdio.h>

struct OrderDetails {
    float total_cost;
    float price_for_one;
};

struct OrderDetails getOrderDetails(unsigned number_of_ordered, float quantity_price) {
    struct OrderDetails result;
    result.price_for_one = number_of_ordered < 10 ? quantity_price * 1.2 : quantity_price;

    result.total_cost = number_of_ordered * result.price_for_one;

    return result;
}

int main(void) {
    float quantity_price;
    unsigned ordered;

    printf("Podaj cene hurtowa: \n");
    scanf("%f", &quantity_price);

    printf("Podaj liczbe zamowionych sztuk: \n");
    scanf("%u", &ordered);

    struct OrderDetails orderDetails = getOrderDetails(ordered, quantity_price);

    printf("\nCalkowity koszt: %f\n", orderDetails.total_cost);
    printf("Koszt za sztuke: \n", orderDetails.price_for_one);

    return 0;
}