#ifndef POINCARE_BASELINE_RELATIVE_LAYOUT_H
#define POINCARE_BASELINE_RELATIVE_LAYOUT_H

#include <poincare/expression.h>
#include <poincare/expression_layout.h>

class BaselineRelativeLayout : public ExpressionLayout {
  public:
    enum class Type {
      Subscript,
      Superscript
    };
    BaselineRelativeLayout(ExpressionLayout * baseLayout, ExpressionLayout * indiceLayout, Type type);
    ~BaselineRelativeLayout();
  protected:
    void render(KDContext * ctx, KDPoint p, KDColor expressionColor, KDColor backgroundColor) override;
    KDSize computeSize() override;
    ExpressionLayout * child(uint16_t index) override;
    KDPoint positionOfChild(ExpressionLayout * child) override;
  private:
    constexpr static KDCoordinate k_indiceHeight = 5;
    ExpressionLayout * m_baseLayout;
    ExpressionLayout * m_indiceLayout;
    Type m_type;
};

#endif